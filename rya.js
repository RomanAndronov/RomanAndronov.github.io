var i;
var Files = new Array();
var Entries = new Array();

Files[ 0 ] = "pdpic/ryapdpic.html";
Entries[ 0 ] = "Practical Design Patterns in C";

Files[ 1 ] = "isc/ryaisc.html";
Entries[ 1 ] = "Software Construction";

Files[ 2 ] = "ryalegal.html";
Entries[ 2 ] = "Legal";

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
