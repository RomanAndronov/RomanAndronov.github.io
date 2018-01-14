
var i;
var Files = new Array();
var Entries = new Array();

Files[ 0 ] = "../index.html";
Entries[ 0 ] = "Home";

Files[ 1 ] = "ryainversion.html";
Entries[ 1 ] = "Inversion";

Files[ 2 ] = "rcircle/ryairc.html";
Entries[ 2 ] = "Real Circle";

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
