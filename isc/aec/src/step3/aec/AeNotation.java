package aec;

import java.util.ArrayList;

interface AeNotation
{
	public String		name();

	public char		openingOOEM();
	public char		closingOOEM();

	public void		prepareOperand( StringBuilder operand );

	public void		rewind( String input );
	public boolean		eoi();
	public int		curr();
	public int		ln();
	public int		col();
	public void		setLn();
	public void		setCol();
	public void		moveNext();
	public void		movePrev();

	public void		qAdd( ArrayList<AeItem> q, AeItem item );
	public AeItem		qRm(  ArrayList<AeItem> q );
}
