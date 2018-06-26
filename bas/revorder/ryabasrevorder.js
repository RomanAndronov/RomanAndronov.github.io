var i;
var Files = new Array();
var Entries = new Array();

Files[ 0 ] = "../../index.html";
Entries[ 0 ] = "Home";

Files[ 1 ] = "../ryabas.html";
Entries[ 1 ] = "Basic Approaches";

Files[ 2 ] = "ryabasrevorder.html";
Entries[ 2 ] = "Reverse Order";

Files[ 3 ] = "ryabasrevorderds.html";
Entries[ 3 ] = "Devil, Swans";

Files[ 4 ] = "ryabasrevorder2eggs.html";
Entries[ 4 ] = "Two Eggs";

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
