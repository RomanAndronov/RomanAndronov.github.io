
var i;
var Files = new Array();
var Entries = new Array();

Files[ 0 ] = "../../index.html";
Entries[ 0 ] = "Home";

Files[ 1 ] = "../ryabas.html";
Entries[ 1 ] = "Basic Approaches";

Files[ 2 ] = "ryabasdivision.html";
Entries[ 2 ] = "Division";

Files[ 3 ] = "./areas/ryabasdivisionareas.html";
Entries[ 3 ] = "Areas";

Files[ 4 ] = "./volumes/ryabasdivisionvolumes.html";
Entries[ 4 ] = "Volumes";

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
