package aec;

class Prefix
	implements AeNotation
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
}
