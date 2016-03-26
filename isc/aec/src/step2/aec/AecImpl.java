package aec;

class AecImpl
{
	AecImpl( Aec aec )
	{
		this.aec = aec;

		debug = false;
		strbldr = new StringBuilder();

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

		return true;
	}

	void
	mkOutputExpression( StringBuilder oe )
	{
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

	Aec				aec;

	StringBuilder			strbldr;

	private int			ontp;
	private AeNotation[]		ons;

	private boolean			debug;
	private int			result;
}
