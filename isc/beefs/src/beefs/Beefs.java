package beefs;

/*
   By Roman Andronov
 */

public
class Beefs
{
	public
	Beefs()
	{
		impl = new BeefsImpl( this );
	}

	/*
	   Convert a Boolean expression in an infix notation
	   into its equivalent in a prefix or postfix notation
	 */
	public boolean
	infixTo( String infixbe, int notationType )
	{
		boolean		rv = false;

		rv = impl.infixTo( infixbe, notationType );

		return rv;
	}

	public void
	mkOutputExpression( StringBuilder oe )
	{
		impl.mkOutputExpression( oe );
	}

	/*
	   compute() returns:

	   true if the input Boolean expression is well
	    formed and has a meaningful Boolean equivalent
	    retrievable via result()

	   false if the input Boolean expression is
	    malformed and has no meaningful Boolean equivalent

	    Retrieve the latest error via err()
	 */
	public boolean
	compute( String tf, boolean cs )
	{
		boolean		rv = false;

		rv = impl.compute( tf, cs );

		return rv;
	}

	public boolean
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
		Beefs			beefs = null;
		int			on = PREFIX;
		boolean			cs = false;

		String			be = System.getProperty( "be", "" );
		String			tf = System.getProperty( "tf", "" );
		String			onstr = System.getProperty( "on", "prefix" );
		String			csstr = System.getProperty( "cs", null );
		String			dbgstr = System.getProperty( "dbg", null );
		StringBuilder		oexpr = new StringBuilder();


		if ( be.length() == 0 || tf.length() == 0 )
		{
			usage();
			return;
		}

		if ( onstr.equalsIgnoreCase( "postfix" ) )
		{
			on = POSTFIX;
		}

		beefs = new Beefs();

		if ( csstr != null )
		{
			cs = true;
		}

		if ( dbgstr != null )
		{
			beefs.dbg( true );
		}

		if ( beefs.infixTo( be, on ) != true )
		{
			System.err.println( beefs.err() );
			return;
		}

		beefs.mkOutputExpression( oexpr );
		System.out.println( oexpr.toString() );

		rv = beefs.compute( tf, cs );
		if ( rv == false )
		{
			System.out.println( beefs.err() );
		}
		else
		{
			System.out.println( beefs.result() );
		}
	}


	private static void
	usage()
	{
		System.err.println( "Usage:" );
		System.err.println( "java -Dbe=expression " +
			"-Dtf=phrase " +
			"[-Don=postfix|prefix] " +
			"[-Dcs] " +
			"[-Ddbg] -jar beefs.jar" );
		System.err.println( "\tbe=expression - an input Boolean expression " +
			"rendered in an infix notation" );
		System.err.println( "\ttf=phrase - a test phrase" );
		System.err.println( "\ton=prefix|postfix - an output notation " +
			"(prefix is default)" );
		System.err.println( "\tcs - do case sensitive word matching " +
			"(case insensitive matching is default)" );
		System.err.println( "\tdbg - print debugging information " +
			"(off is default)" );
	}

	public static final int		PREFIX = 0;
	public static final int		POSTFIX = 1;

	BeefsImpl			impl = null;
}
