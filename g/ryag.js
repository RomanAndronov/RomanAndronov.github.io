
var i;
var Files = new Array();
var Entries = new Array();

Files[ 0 ] = "../index.html";
Entries[ 0 ] = "Home";

Files[ 1 ] = "ryag.html";
Entries[ 1 ] = "g";

Files[ 2 ] = "ryagobjs.html";
Entries[ 2 ] = "Objects";

Files[ 3 ] = "ryagops.html";
Entries[ 3 ] = "Operators";

Files[ 4 ] = "ryagstmnts.html";
Entries[ 4 ] = "Statements";

Files[ 5 ] = "ryagint.html";
Entries[ 5 ] = "Interpretation";

Files[ 6 ] = "ryagsmpls.html";
Entries[ 6 ] = "Samples";

Files[ 7 ] = "ryagshcuts.html";
Entries[ 7 ] = "Shortcuts";

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
