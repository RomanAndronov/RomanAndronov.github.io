package aec;

class Postfix
	implements AeNotation
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
}
