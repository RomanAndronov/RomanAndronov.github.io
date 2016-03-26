
var i;
var Files = new Array();
var Entries = new Array();

Files[ 0 ] = "../../index.html";
Entries[ 0 ] = "Home";

Files[ 1 ] = "../ryaisc.html";
Entries[ 1 ] = "Software Construction";

Files[ 2 ] = "ryaiscaec.html";
Entries[ 2 ] = "AEC";

Files[ 3 ] = "ryaiscaec1.html";
Entries[ 3 ] = "Step 1";

Files[ 4 ] = "ryaiscaec2.html";
Entries[ 4 ] = "Step 2";

Files[ 5 ] = "ryaiscaec3.html";
Entries[ 5 ] = "Step 3";

Files[ 6 ] = "ryaiscaec4.html";
Entries[ 6 ] = "Step 4";

Files[ 7 ] = "ryaiscaec5.html";
Entries[ 7 ] = "Step 5";

Files[ 8 ] = "ryaiscaec6.html";
Entries[ 8 ] = "Step 6";

Files[ 9 ] = "ryaiscaec7.html";
Entries[ 9 ] = "Step 7";

Files[ 10 ] = "ryaiscaec8.html";
Entries[ 10 ] = "Step 8";

Files[ 11 ] = "ryaiscaecepilog.html";
Entries[ 11 ] = "Epilog";

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
