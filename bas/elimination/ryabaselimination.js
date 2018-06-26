
var i;
var Files = new Array();
var Entries = new Array();

Files[ 0 ] = "../../index.html";
Entries[ 0 ] = "Home";

Files[ 1 ] = "../ryabas.html";
Entries[ 1 ] = "Basic Approaches";

Files[ 2 ] = "ryabaselimination.html";
Entries[ 2 ] = "Elimination";

Files[ 3 ] = "ryabasalign4coins.html";
Entries[ 3 ] = "Align 4 Coins";

Files[ 4 ] = "ryabascassini.html";
Entries[ 4 ] = "Cassini Paradox";

Files[ 5 ] = "ryabasfish.html";
Entries[ 5 ] = "Who Owns the Fish?";

Files[ 6 ] = "ryabasommp1.html";
Entries[ 6 ] = "Omnia Mea Mecum Porto 1";

Files[ 7 ] = "ryabasommp2.html";
Entries[ 7 ] = "Omnia Mea Mecum Porto 2";

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
