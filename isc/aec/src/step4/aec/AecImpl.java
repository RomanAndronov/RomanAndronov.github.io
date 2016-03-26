package aec;

import java.util.Stack;
import java.util.ArrayList;

class AecImpl
{
	AecImpl( Aec aec )
	{
		this.aec = aec;

		debug = false;
		strbldr = new StringBuilder();

		irdr = new IReader();
		stack = new Stack<AeItem>();
		queue = new ArrayList<AeItem>();

		ontp = Aec.PREFIX;
		ons = new AeNotation[] { new Prefix(), new Postfix() };
	}

	/*
	   Convert an input arithmetic expression
	   rendered in an infix notation into its
	   equivalent in a prefix or prostfix notation
	 */
	boolean
	infixTo( String infixae, int ontp )
	{
		AeItem		item = null;


		this.ontp = ontp;

		stack.clear();
		queue.clear();
		irdr.setInput( infixae, ons[ ontp ] );

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
		 */
		while ( stack.empty() == false )
		{
			item = stack.pop();

			ons[ ontp ].qAdd( queue, item );

			printState();
		}

		return true;
	}

	void
	mkOutputExpression( StringBuilder oe )
	{
		int		N = queue.size();
		AeItem		item = null;


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
	compute()
	{
		return true;
	}

	int
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
	processItem( AeItem newitem )
	{
		if ( newitem.type == 'a' )
		{
			ons[ ontp ].qAdd( queue, newitem );
		}
		else if ( newitem.type == 'o' )
		{
			stack.push( newitem );
		}

		return true;
	}

	private void
	printState()
	{
		int			i = 0;
		int			N = 0;
		AeItem			item = null;

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


	Aec				aec = null;

	StringBuilder			strbldr = null;

	IReader				irdr = null;

	Stack<AeItem>			stack = null;
	ArrayList<AeItem>		queue = null;

	private int			ontp = -1;
	private AeNotation[]		ons = null;

	private boolean			debug = false;
	private int			result = 0;
}
