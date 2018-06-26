var i;
var Files = new Array();
var Entries = new Array();

Files[ 0 ] = "../../index.html";
Entries[ 0 ] = "Home";

Files[ 1 ] = "../ryabas.html";
Entries[ 1 ] = "Basic Approaches";

Files[ 2 ] = "ryabasequiv.html";
Entries[ 2 ] = "Equivalence";

Files[ 3 ] = "ryabasarmies.html";
Entries[ 3 ] = "Armies";

Files[ 4 ] = "ryabasrlb1.html";
Entries[ 4 ] = "Roliding Bead 1";

Files[ 5 ] = "ryabasrlb2.html";
Entries[ 5 ] = "Roliding Bead 2";

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
