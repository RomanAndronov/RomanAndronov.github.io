package aec;

public
class Aec
{
	public
	Aec()
	{
		impl = new AecImpl( this );
	}

	/*
	   Convert an arithemtic expression in an infix notation
	   into its equivalent in a prefix or postfix notation
	 */
	public boolean
	infixTo( String infixae, int notationType )
	{
		boolean		rv = false;

		rv = impl.infixTo( infixae, notationType );

		return rv;
	}

	public void
	mkOutputExpression( StringBuilder oe )
	{
		impl.mkOutputExpression( oe );
	}

	/*
	   compute() returns:

	   true if the input arithmetic expression is well
	    formed and has a meaningful numeric equivalent
	    retrievable via result()

	   false if the input arithmetic expression is
	    malformed and has no meaningful numeric equivalent

	    Retrieve the latest error via err()
	 */
	public boolean
	compute()
	{
		boolean		rv = false;

		rv = impl.compute();

		return rv;
	}

	public int
	result()
	{
		return impl.result();
	}

	public String
	err()
	{
		return impl.err();
	}

	public boolean
	dbg( boolean dbg )
	{
		return impl.dbg( dbg );
	}

	public static void
	main( String[] args )
	{
		boolean			rv = false;
		Aec			aec = null;
		int			on = PREFIX;
		String			ae = System.getProperty( "ae", "" );
		String			onstr = System.getProperty( "on", "prefix" );
		String			dbgstr = System.getProperty( "dbg", null );
		StringBuilder		oexpr = new StringBuilder();


		if ( ae.length() == 0 )
		{
			usage();
			return;
		}

		if ( onstr.equalsIgnoreCase( "postfix" ) )
		{
			on = POSTFIX;
		}

		aec = new Aec();

		if ( dbgstr != null )
		{
			aec.dbg( true );
		}

		if ( aec.infixTo( ae, on ) != true )
		{
			System.err.println( aec.err() );
			return;
		}

		aec.mkOutputExpression( oexpr );
		System.out.println( oexpr.toString() );

		rv = aec.compute();
		if ( rv == false )
		{
			System.out.println( aec.err() );
		}
		else
		{
			System.out.println( aec.result() );
		}
	}


	private static void
	usage()
	{
		System.err.println( "Usage:" );
		System.err.println( "java -Dae=expression " +
			"[-Don=postfix|prefix] " +
			"[-Ddbg] -jar aec.jar" );
		System.err.println( "\tae=expression - an input arithmetic expression " +
			"rendered in an infix notation" );
		System.err.println( "\ton=prefix|postfix - an output notation " +
			"(prefix is default)" );
		System.err.println( "\tdbg - print debugging information " +
			"(off is default)" );
	}

	public static final int		PREFIX = 0;
	public static final int		POSTFIX = 1;

	AecImpl				impl = null;
}
