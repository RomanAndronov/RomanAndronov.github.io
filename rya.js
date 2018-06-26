
var i;
var Files = new Array();
var Entries = new Array();

Files[ 0 ] = "pdpic/ryapdpic.html";
Entries[ 0 ] = "Practical Design Patterns in C";

Files[ 1 ] = "bas/ryabas.html";
Entries[ 1 ] = "Basic Approaches";

Files[ 2 ] = "isc/ryaisc.html";
Entries[ 2 ] = "Software Construction";

Files[ 3 ] = "g/ryag.html";
Entries[ 3 ] = "g";

Files[ 4 ] = "pse/ryapse.html";
Entries[ 4 ] = "Experiments";

Files[ 5 ] = "tria/ryatria.html";
Entries[ 5 ] = "Triangle";

Files[ 6 ] = "inversion/ryainversion.html";
Entries[ 6 ] = "Inversion";

Files[ 7 ] = "pgc/ryapgci.html";
Entries[ 7 ] = "Gear Clocks";

Files[ 8 ] = "tutorials/ryatutorials.html";
Entries[ 8 ] = "Tutorials";

Files[ 9 ] = "ryalegal.html";
Entries[ 9 ] = "Legal";

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
