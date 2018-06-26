
var i;
var Files = new Array();
var Entries = new Array();

Files[ 0 ] = "../../index.html";
Entries[ 0 ] = "Home";

Files[ 1 ] = "../ryabas.html";
Entries[ 1 ] = "Basic Approaches";

Files[ 2 ] = "ryabasequation.html";
Entries[ 2 ] = "Equation";

Files[ 3 ] = "ryabaspythagoras.html";
Entries[ 3 ] = "Pythagorean Theorem";

Files[ 4 ] = "ryabaschase.html";
Entries[ 4 ] = "Chase Around the Clock";

document.write( "<br>" );
document.write( "<ul>" );
for ( i = 0; i < Files.length; i++ )
{
	document.write( "<li><a href=\"" + 
		Files[ i ] + 
		"\">" + 
		Entries[ i ] + 
		"</a></li>" );
}
document.write( "</ul>" );
document.write( "<br>" );
