var i;
var Files = new Array();
var Entries = new Array();

Files[ 0 ] = "../../../index.html";
Entries[ 0 ] = "Home";

Files[ 1 ] = "../../ryabas.html";
Entries[ 1 ] = "Basic Approaches";

Files[ 2 ] = "../ryabasdivision.html";
Entries[ 2 ] = "Division";

Files[ 3 ] = "ryabasdivisionareas.html";
Entries[ 3 ] = "Areas";

Files[ 4 ] = "ryabasline.html";
Entries[ 4 ] = "Line";

Files[ 5 ] = "ryabasparabola.html";
Entries[ 5 ] = "Parabola";

Files[ 6 ] = "ryabassquareroot.html";
Entries[ 6 ] = "Square Root";

Files[ 7 ] = "ryabascircle.html";
Entries[ 7 ] = "Circle";

Files[ 8 ] = "ryabasellipse.html";
Entries[ 8 ] = "Ellipse";

Files[ 9 ] = "ryabassine.html";
Entries[ 9 ] = "Sine";

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
