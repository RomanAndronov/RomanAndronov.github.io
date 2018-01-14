
var i;
var Files = new Array();
var Entries = new Array();

Files[ 0 ] = "../index.html";
Entries[ 0 ] = "Home";

Files[ 1 ] = "ryapgci.html";
Entries[ 1 ] = "Introduction";

Files[ 2 ] = "ryapgcp.html";
Entries[ 2 ] = "Pendulum";

Files[ 3 ] = "ryapgce.html";
Entries[ 3 ] = "Escapement";

Files[ 4 ] = "ryapgch.html";
Entries[ 4 ] = "Hands";


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
