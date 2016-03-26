package beefs;

/*
   By Roman Andronov
 */

class BeItem
{
	BeItem()
	{
	}

	void
	mkOperand( String a, int ln, int col )
	{
		type = 'a';
		this.ln = ln;
		this.col = col;
		operand = a;
	}

	void
	mkOperator( char op, int ln, int col )
	{
		sym = op;
		this.ln = ln;
		this.col = col;


		if ( op == '(' || op == ')' )
		{
			type = 'p';
		}
		else
		{
			type = 'o';
		}

		/*
		   In the descending order of precedence
		 */
		if ( op == '!' )
		{
			assoc = 'r';
			prec = 100;
			noo = 1;
		}
		else if ( op == '&' )
		{
			assoc = 'l';
			prec = 99;
			noo = 2;
		}
		else if ( op == '^' )
		{
			assoc = 'l';
			prec = 98;
			noo = 2;
		}
		else if ( op == '|' )
		{
			assoc = 'l';
			prec = 97;
			noo = 2;
		}
		else if ( op == 'E' )
		{
			assoc = 'r';
			prec = 0;
			noo = 1;
		}
	}

	static boolean
	isOperator( char c )
	{
		if ( c == '!' || c == '&' ||
			c == '^' || c == '|' ||
			c == '(' || c == ')' )
		{
			return true;
		}

		return false;
	}

	boolean
	findWord( String[] words, boolean cs )
	{
		if ( type == 'b' )
		{
			return bv;
		}

		boolean			cmp = false;

		for ( int i = 0; i < words.length; i++ )
		{
			if ( cs == true )
			{
				cmp = operand.equals( words[ i ] );
			}
			else
			{
				cmp = operand.equalsIgnoreCase( words[ i ] );
			}

			if ( cmp == true )
			{
				return true;
			}
		}

		return false;
	}

	void
	print( StringBuilder sb )
	{
		sb.append( "[" );

		if ( type == 'a' )
		{
			sb.append( operand );
		}
		else
		{
			sb.append( sym );
		}

		sb.append( "{" );
		sb.append( ln );
		sb.append( "." );
		sb.append( col );
		sb.append( "}]" );
	}


	/*
	   'a' = operand (argument)
	   'b' = Boolean value
	   'o' = operator
	   'p' = parenthesis (OOEMs)
	 */
	char		type = '\0';


	/*
	   Used if type is 'a'
	 */
	String		operand = null;


	/*
	   Used if type is 'b'
	 */
	boolean		bv = false;


	/*
	   The following members are used if
	   item type is not 'a'

	   Printable symbol
	 */
	char		sym = '\0';


	/*
	   Associativity

	   'r' is right to left,
	   'l' is left to right.
	 */
	char		assoc = '\0';


	/*
	   Precedence
	 */
	int		prec = -1;


	/*
	   Number of operands
	 */
	int		noo = -1;


	/*
	   The position of this item
	   within the input
	 */
	int		ln = -1;
	int		col = -1;

}
