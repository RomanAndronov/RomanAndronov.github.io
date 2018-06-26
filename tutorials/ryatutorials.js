
var i;
var Files = new Array();
var Entries = new Array();

Files[ 0 ] = "../index.html";
Entries[ 0 ] = "Home";

Files[ 1 ] = "ryatutorials.html";
Entries[ 1 ] = "Tutorials";

Files[ 2 ] = "kp/ryakp.html";
Entries[ 2 ] = "Kombinatorix Primordial";

Files[ 3 ] = "gcd/ryagcd.html";
Entries[ 3 ] = "GCD";

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
