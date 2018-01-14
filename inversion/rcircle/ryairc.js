var i;
var Files = new Array();
var Entries = new Array();

Files[ 0 ] = "../../index.html";
Entries[ 0 ] = "Home";

Files[ 1 ] = "../ryainversion.html";
Entries[ 1 ] = "Inversion";

Files[ 2 ] = "ryairc.html";
Entries[ 2 ] = "Real Circle";

Files[ 3 ] = "ryaircp.html";
Entries[ 3 ] = "Points";

Files[ 4 ] = "ryaircsl.html";
Entries[ 4 ] = "Straight Lines";

Files[ 5 ] = "ryaircc.html";
Entries[ 5 ] = "Circles";

Files[ 6 ] = "ryairca.html";
Entries[ 6 ] = "Angles";

Files[ 7 ] = "ryairca.html";
Entries[ 7 ] = "Tangency, Power";

Files[ 8 ] = "ryaircp01.html";
Entries[ 8 ] = "Problems 01";

Files[ 9 ] = "ryaircp02.html";
Entries[ 9 ] = "Problems 02";

Files[ 10 ] = "ryaircp03.html";
Entries[ 10 ] = "Problems 03";

Files[ 11 ] = "ryaircp04.html";
Entries[ 11 ] = "Problems 04";

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
