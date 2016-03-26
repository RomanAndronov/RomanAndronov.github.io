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
				ons[ ontp ].qAdd( queue, item );
			}
			else
			{
				/*
				   No more input
				 */
				break;
			}
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
