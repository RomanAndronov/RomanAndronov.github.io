package beefs;

/*
   By Roman Andronov
 */

import java.util.ArrayList;

class Prefix
	implements BeNotation
{
	Prefix()
	{
	}

	public char
	openingOOEM()
	{
		return ')';
	}

	public char
	closingOOEM()
	{
		return '(';
	}

	public String
	name()
	{
		return "prefix";
	}

	public void
	prepareOperand( StringBuilder operand )
	{
		/*
		   Since input is read right to left
		   reverse the characters that make up
		   the argument: "cba" becomes "abc".

		   Adjust the column number of where
		   this argument is seen within the input
		 */
		operand.reverse();
		setCol();
	}

	/*
	   The input is read right to left
	 */
	public void
	rewind( String input )
	{
		inputsz = col = input.length();

		curr = col - 1;

		ln = 1;
		for ( int i = 0; i < inputsz; i++ )
		{
			if ( input.charAt( i ) == '\n' )
			{
				ln++;
			}
		}
	}

	public boolean
	eoi()
	{
		if ( curr < 0 )
		{
			return true;
		}

		return false;
	}

	public int
	curr()
	{
		return curr;
	}

	public int
	ln()
	{
		return ln;
	}

	public int
	col()
	{
		return col;
	}

	public void
	setLn()
	{
		ln--;
	}

	public void
	setCol()
	{
		if ( curr < 0 )
		{
			col = 1;
		}
		else
		{
			col = curr + 1;
		}
	}

	public void
	moveNext()
	{
		if ( curr < 0 )
		{
			return;
		}

		curr--;
	}

	public void
	movePrev()
	{
		if ( curr >= ( inputsz - 1 ) )
		{
			return;
		}

		curr++;
	}

	/*
	   Prefix queue is accessed tail to head
	 */
	public void
	qAdd( ArrayList<BeItem> q, BeItem item )
	{
		q.add( 0, item );
	}

	public BeItem
	qRm( ArrayList<BeItem> q )
	{
		BeItem		item = null;
		int		N = q.size();

		if ( N > 0 )
		{
			item = q.remove( N - 1 );
		}

		return item;
	}

	private int			col = -1;
	private int			ln = -1;
	private int			curr = -1;
	private int			inputsz = 0;
}
