
var i;
var Files = new Array();
var Entries = new Array();

Files[ 0 ] = "../index.html";
Entries[ 0 ] = "Home";

Files[ 1 ] = "ryapse.html";
Entries[ 1 ] = "Experiments";

Files[ 2 ] = "ryapserac01.html";
Entries[ 2 ] = "Ruler &amp; Compass 01";

Files[ 3 ] = "ryapserac02.html";
Entries[ 3 ] = "Ruler &amp; Compass 02";

Files[ 4 ] = "ryapserac03.html";
Entries[ 4 ] = "Ruler &amp; Compass 03";

Files[ 5 ] = "ryapserac04.html";
Entries[ 5 ] = "Ruler &amp; Compass 04";

Files[ 6 ] = "ryapse12coins.html";
Entries[ 6 ] = "12 Coins";

Files[ 7 ] = "ryapsebsquare.html";
Entries[ 7 ] = "B Square";


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
