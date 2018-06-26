
var i;
var Files = new Array();
var Entries = new Array();

Files[ 0 ] = "../../index.html";
Entries[ 0 ] = "Home";

Files[ 1 ] = "../ryabas.html";
Entries[ 1 ] = "Basic Approaches";

Files[ 2 ] = "ryabasrearrangement.html";
Entries[ 2 ] = "Rearrangement";

Files[ 3 ] = "ryabassineofasum.html";
Entries[ 3 ] = "sin (a + b)";

Files[ 4 ] = "ryabascosineofasum.html";
Entries[ 4 ] = "cos (a + b)";

Files[ 5 ] = "ryabastanofasum.html";
Entries[ 5 ] = "tan (a + b)";

Files[ 6 ] = "ryabassineofadiff.html";
Entries[ 6 ] = "sin (a - b)";

Files[ 7 ] = "ryabascosineofadiff.html";
Entries[ 7 ] = "cos (a - b)";

Files[ 8 ] = "ryabastanofadiff.html";
Entries[ 8 ] = "tan (a - b)";

Files[ 9 ] = "ryabassums1.html";
Entries[ 9 ] = "Sums 1";

Files[ 10 ] = "ryabassums2.html";
Entries[ 10 ] = "Sums 2";

Files[ 11 ] = "ryabassums3.html";
Entries[ 11 ] = "Sums 3";

Files[ 12 ] = "ryabasstripteez.html";
Entries[ 12 ] = "Strip Teez";

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
