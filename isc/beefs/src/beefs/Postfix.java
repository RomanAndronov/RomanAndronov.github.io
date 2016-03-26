package beefs;

/*
   By Roman Andronov
 */

import java.util.ArrayList;

class Postfix
	implements BeNotation
{
	Postfix()
	{
	}

	public char
	openingOOEM()
	{
		return '(';
	}

	public char
	closingOOEM()
	{
		return ')';
	}

	public String
	name()
	{
		return "postfix";
	}

	public void
	prepareOperand( StringBuilder operand )
	{
		return;
	}

	/*
	   Input is read left to right
	 */
	public void
	rewind( String input )
	{
		curr = 0;
		ln = col = 1;
		inputsz = input.length();
	}

	public boolean
	eoi()
	{
		if ( curr < inputsz )
		{
			return false;
		}

		return true;
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
		ln++;
	}

	public void
	setCol()
	{
		if ( curr >= inputsz )
		{
			col = inputsz;
		}
		else
		{
			col = curr + 1;
		}
	}

	public void
	moveNext()
	{
		if ( curr >= inputsz )
		{
			return;
		}

		curr++;
	}

	public void
	movePrev()
	{
		if ( curr < 1 )
		{
			return;
		}

		curr--;
	}

	/*
	   Postfix queue is accessed from head to tail
	 */
	public void
	qAdd( ArrayList<BeItem> q, BeItem item )
	{
		q.add( item );
	}

	public BeItem
	qRm( ArrayList<BeItem> q )
	{
		BeItem		item = null;

		if ( q.isEmpty() == false )
		{
			item = q.remove( 0 );
		}

		return item;
	}

	private int			col = -1;
	private int			ln = -1;
	private int			curr = -1;
	private int			inputsz = 0;
}
