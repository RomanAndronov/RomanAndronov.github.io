package beefs;

/*
   By Roman Andronov
 */

class IReader
{
	IReader()
	{
	}

	void
	setInput( String infixbe, BeNotation beon )
	{
		input = infixbe;
		outputNotation = beon;
		outputNotation.rewind( input );
	}

	BeItem
	getItem()
	{
		char			ch = '\0';
		BeItem			item = null;


		/*
		   Skip white space
		 */
		while ( !outputNotation.eoi() )
		{
			ch = input.charAt( outputNotation.curr() );
			if ( isSpace( ch ) == false )
			{
				break;
			}

			if ( ch == '\n' )
			{
				outputNotation.setLn();
			}

			outputNotation.moveNext();
		}

		if ( outputNotation.eoi() )
		{
			return null;
		}

		outputNotation.setCol();

		item = new BeItem();
		if ( BeItem.isOperator( ch ) == true )
		{
			item.mkOperator( ch, outputNotation.ln(), outputNotation.col() );
		}
		else
		{
			/*
			   If this item is not an operator
			   then it is a potential operand
			 */
			operand.setLength( 0 );

			while ( !outputNotation.eoi() )
			{
				ch = input.charAt( outputNotation.curr() );

				/*
				   White space or next operator
				   marks the end of this operand
				 */
				if ( isSpace( ch ) == true || BeItem.isOperator( ch ) == true )
				{
					/*
					   End of operand. Put this character
					   back into the input queue
					 */
					outputNotation.movePrev();
					break;
				}

				/*
				   Otherwise - keep assembling the operand
				 */
				operand.append( ch );
				outputNotation.moveNext();
			}
			outputNotation.prepareOperand( operand );
			item.mkOperand( operand.toString(),
				outputNotation.ln(),
				outputNotation.col() );
		}

		outputNotation.moveNext();

		return item;
	}

	static boolean
	isSpace( char c )
	{
		if ( c == ' ' ||
			c == '\t' ||
			c == '\f' ||
			c == '\r' ||
			c == '\n' )
		{
			return true;
		}

		return false;
	}


	private String			input = null;
	private BeNotation		outputNotation = null;
	private StringBuilder		operand = new StringBuilder();
}
