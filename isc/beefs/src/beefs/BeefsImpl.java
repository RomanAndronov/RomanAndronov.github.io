package beefs;

/*
   By Roman Andronov
 */

import java.util.Stack;
import java.util.ArrayList;

class BeefsImpl
{
	BeefsImpl( Beefs beefs )
	{
		this.beefs = beefs;

		debug = false;
		strbldr = new StringBuilder();

		irdr = new IReader();
		stack = new Stack<BeItem>();
		queue = new ArrayList<BeItem>();

		ontp = Beefs.PREFIX;
		ons = new BeNotation[] { new Prefix(), new Postfix() };
	}

	/*
	   Convert an input Boolean expression
	   rendered in an infix notation into its
	   equivalent in a prefix or prostfix notation
	 */
	boolean
	infixTo( String infixbe, int ontp )
	{
		BeItem		item = null;


		this.ontp = ontp;

		stack.clear();
		queue.clear();
		irdr.setInput( infixbe, ons[ ontp ] );

		while ( true )
		{
			item = irdr.getItem();
			if ( item != null )
			{
				if ( processItem( item ) != true )
				{
					return false;
				}

				printState();
			}
			else
			{
				/*
				   No more input
				 */
				break;
			}
		}

		/*
		   Remove all operators from stack
		   and add them to output queue

		   Dangling parentheses signal a syntax error
		 */
		while ( stack.empty() == false )
		{
			item = stack.pop();
			if ( item.type == 'p' )
			{
				mkErr( INFIXTO, ERR_PNB, item );
				return false;
			}

			ons[ ontp ].qAdd( queue, item );

			printState();
		}

		/*
		   If there is only one item in the output queue
		   and it is an argument then manufacture an
		   Exists operator and add it to the output queue
		 */
		if ( queue.size() == 1 )
		{
			item = queue.get( 0 );
			if ( item.type == 'a' )
			{
				BeItem		e = new BeItem();

				e.mkOperator( 'E', -1, -1 );
				ons[ ontp ].qAdd( queue, e );
			}
			else
			{
				mkErr( INFIXTO, ERR_MFBE, item );
				return false;
			}
		}

		return true;
	}

	void
	mkOutputExpression( StringBuilder oe )
	{
		int		N = queue.size();
		BeItem		item = null;


		oe.setLength( 0 );
		oe.append( ons[ ontp ].name() +
			" queue, " + N + " item(s):\n" );

		for ( int i = 0; i < N; i++ )
		{
			item = queue.get( i );
			item.print( oe );
		}
	}

	boolean
	compute( String phrase, boolean cs )
	{
		boolean		rv = false;
		BeItem		item = null;
		String[]	words = phrase.trim().split( "\\s+" );


		stack.clear();

		while ( queue.isEmpty() == false )
		{
			item = ons[ ontp ].qRm( queue );
			if ( item.type == 'a' )
			{
				stack.push( item );
			}
			else
			{
				rv = executeOperator( item, words, cs );
				if ( rv == false )
				{
					return rv;
				}

				item.type = 'b';
				item.bv = result;
				stack.push( item );
			}
		}

		if ( stack.size() != 1 )
		{
			item = stack.size() > 0 ? stack.peek() : null;
			mkErr( COMPUTE, ERR_MFBE, item );
			return false;
		}

		item = stack.pop();

		result = item.bv;

		return true;
	}

	boolean
	result()
	{
		return result;
	}

	String
	err()
	{
		return strbldr.toString();
	}

	boolean
	dbg( boolean dbg )
	{
		boolean		rv = debug;

		debug = dbg;

		return rv;
	}

	private boolean
	processItem( BeItem newitem )
	{
		if ( newitem.type == 'a' )
		{
			ons[ ontp ].qAdd( queue, newitem );
		}
		else if ( newitem.sym == ons[ ontp ].openingOOEM() )
		{
			/*
			   Add output notation-specific opening OOEM
			   to the stack temporarily: it will be used
			   as a signal for the code handling the
			   closing OOEM, see below
			 */
			stack.push( newitem );
		}
		else if ( newitem.sym == ons[ ontp ].closingOOEM() )
		{
			if ( addClosingOOEM( newitem ) == false )
			{
				return false;
			}
		}
		else if ( newitem.type == 'o' )
		{
			if ( addOperator( newitem ) == false )
			{
				return false;
			}
		}

		return true;
	}

	private boolean
	addClosingOOEM( BeItem cp )
	{
		BeItem		currop = null;
		boolean		balanced = false;


		/*
		   As long as an operator at the top of the
		   stack is not a balancing notation-specific
		   opening OOEM, remove it from the stack and
		   add it to the output queue.

		   If stack is emptied and no opening OOEM has
		   been seen then it signals a syntax error -
		   this OOEM is not balanced.

		   Once removed, both OOEMs are thrown out
		 */
		while ( stack.empty() == false )
		{
			currop = stack.pop();

			if ( currop.sym == ons[ ontp ].openingOOEM() )
			{
				balanced = true;
				break;
			}
			else
			{
				ons[ ontp ].qAdd( queue, currop );
			}
		}

		if ( balanced == false )
		{
			mkErr( ACOOEM, ERR_PNB, cp );
			return false;
		}

		return true;
	}

	private boolean
	addOperator( BeItem newop )
	{
		int		rv = 0;
		BeItem		currop = null;


		while ( stack.empty() == false )
		{
			currop = stack.peek();

			if ( currop.type == 'p' )
			{
				break;
			}
			else if ( newop.prec < currop.prec )
			{
				/*
				   Higher precedence operators go
				   into the output queue first to
				   be executed first
				 */
				currop = stack.pop();
				ons[ ontp ].qAdd( queue, currop );
			}
			else if ( newop.prec == currop.prec )
			{
				rv = addSamePrecOperator( newop, currop );
				if ( rv == -1 )
				{
					break;
				}
				else if ( rv == 0 )
				{
					return false;
				}
			}
			else
			{
				/*
				   If a new operator is of higher precedence
				   than the previous one then add it to the
				   stack to ensure that it is executed first
				 */
				break;
			}
		}

		stack.push( newop );

		return true;
	}

	/*
	   addSamePrecOperator() is invoked in a loop.

	   Its return values mean:

	    1 = stay in the loop
	    0 = return failure
	   -1 = break out of the loop
	 */
	private int
	addSamePrecOperator( BeItem newop, BeItem currop )
	{
		if ( newop.assoc != currop.assoc )
		{
			String	what = "associativity conflict with " +
					currop.sym + " at ln: " +
					currop.ln + ", col: " +
					currop.col;
			mkErr( ADDSPOP, what, newop );
			return 0;
		}
		else if ( newop.assoc == 'l' )
		{
			if ( ontp == Beefs.POSTFIX )
			{
				/*
				   Postfix notation:
				   Since the left-associative operators are
				   discovered in a left to right order in the
				   input, move same-precedence left-associative
				   operators from the stack into the output
				   queue to ensure that they are executed in a
				   proper, left to right, order
				 */
				currop = stack.pop();
				ons[ ontp ].qAdd( queue, currop );
			}
			else
			{
				/*
				   Prefix notation:
				   Since the left-associative operators
				   are discovered in a right to left order
				   in the input,  keep accumulating them
				   on the stack.

				   When such operators are removed from the
				   the stack they will be placed in the
				   output queue in reverse order that will
				   ensure their proper, left to right,
				   execution order
				 */
				return -1;
			}
		}
		else
		{
			/*
			   These operators are right-associative
			 */
			if ( ontp == Beefs.PREFIX )
			{
				/*
				   Prefix notation:
				   Since the right-associative operators are
				   discovered in a right to left order in the
				   input, move same-precedence right-associative
				   operators from the stack into the output
				   queue to ensure that they are executed in a
				   proper, right to left, order
				 */
				currop = stack.pop();
				ons[ ontp ].qAdd( queue, currop );
			}
			else
			{
				/*
				   Postfix notation:
				   Since the right-associative operators are
				   discovered in a left to right order in the
				   input, keep accumulating them on the stack.

				   When such operators are removed from the
				   the stack they will be placed in the
				   output queue in reverse order that will
				   ensure their proper, right to left,
				   execution order
				 */
				return -1;
			}
		}

		return 1;
	}

	private boolean
	executeOperator( BeItem op, String[] words, boolean cs )
	{
		BeItem			right = null;
		BeItem			left = null;
		int			stacksz = stack.size();


		if ( stacksz < op.noo )
		{
			String		what = "not enough arguments on stack: " +
						stacksz + ", need " + op.noo;

			mkErr( EXEOP, what, op );
			return false;
		}

		if ( op.noo == 1 )
		{
			right = stack.pop();
		}
		else
		{
			if ( ontp == Beefs.POSTFIX )
			{
				right = stack.pop();
				left = stack.pop();
			}
			else
			{
				left = stack.pop();
				right = stack.pop();
			}
		}

		if ( op.sym == '!' )
		{
			result = executeNot( words, cs, right );
		}
		else if ( op.sym == '&' )
		{
			result = executeAnd( words, cs, left, right );
		}
		else if ( op.sym == '^' )
		{
			result = executeXor( words, cs, left, right );
		}
		else if ( op.sym == '|' )
		{
			result = executeOr( words, cs, left, right );
		}
		else if ( op.sym == 'E' )
		{
			result = executeExists( words, cs, right );
		}

		if ( debug )
		{
			strbldr.setLength( 0 );
			strbldr.append( result + " = " );
			left.print( strbldr );
			strbldr.append( " " + op.sym + " " );
			right.print( strbldr );
			System.out.println( strbldr.toString() );
		}

		return true;
	}

	private boolean
	executeNot( String[] words, boolean cs, BeItem right )
	{
		boolean			rv = false;

		rv = !right.findWord( words, cs );

		return rv;
	}

	private boolean
	executeAnd( String[] words, boolean cs, BeItem left, BeItem right )
	{
		boolean			rv = false;

		rv = left.findWord( words, cs );
		if ( rv == false )
		{
			return false;
		}

		rv = right.findWord( words, cs );

		return rv;
	}

	private boolean
	executeXor( String[] words, boolean cs, BeItem left, BeItem right )
	{
		boolean			lhs = false;
		boolean			rhs = false;
		boolean			rv = false;

		lhs = left.findWord( words, cs );
		rhs = right.findWord( words, cs );

		rv = lhs ^ rhs;

		return rv;
	}

	private boolean
	executeOr( String[] words, boolean cs, BeItem left, BeItem right )
	{
		boolean			rv = false;

		rv = left.findWord( words, cs );
		if ( rv == true )
		{
			return true;
		}

		rv = right.findWord( words, cs );

		return rv;
	}

	private boolean
	executeExists( String[] words, boolean cs, BeItem right )
	{
		boolean			rv = false;

		rv = right.findWord( words, cs );

		return rv;
	}

	private void
	mkErr( String where, String what, BeItem optitem )
	{
		strbldr.setLength( 0 );
		strbldr.append( "beefs: error: " + where + ": "  + what );
		if ( optitem != null )
		{
			strbldr.append( ": " );
			optitem.print( strbldr );
		}
	}

	private void
	printState()
	{
		int			i = 0;
		int			N = 0;
		BeItem			item = null;

		if ( !debug )
		{
			return;
		}

		strbldr.setLength( 0 );

		N = queue.size();
		strbldr.append( ons[ ontp ].name() );
		strbldr.append( " queue: " );
		for ( i = 0; i < N; i++ )
		{
			item = queue.get( i );
			item.print( strbldr );
		}
		strbldr.append( "\n" );

		strbldr.append( "stack: " );
		N = stack.size();
		if ( N == 0 )
		{
			strbldr.append( "{}\n" );
		}

		for ( i = N - 1; i > -1; i-- )
		{
			item = stack.get( i );
			strbldr.append( "\t" );
			item.print( strbldr );
			strbldr.append( "\n" );
		}

		System.out.println( strbldr.toString() );
	}


	Beefs				beefs = null;

	StringBuilder			strbldr = null;

	IReader				irdr = null;

	Stack<BeItem>			stack = null;
	ArrayList<BeItem>		queue = null;

	private int			ontp = -1;
	private BeNotation[]		ons = null;

	private boolean			debug = false;
	private boolean			result = false;

	private static final String	INFIXTO = "BeefsImpl.infixTo()";
	private static final String	COMPUTE = "BeefsImpl.compute()";
	private static final String	ADDSPOP = "BeefsImpl.addSamePrecOp()";
	private static final String	ACOOEM = "BeefsImpl.addClosingOOEM()";
	private static final String	EXEOP = "BeefsImpl.executeOperator()";

	private static final String	ERR_PNB = "() not balanced";
	private static final String	ERR_MFBE = "malformed Boolean expression";
}
