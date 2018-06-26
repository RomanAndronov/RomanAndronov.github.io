var i;
var Files = new Array();
var Entries = new Array();

Files[ 0 ] = "../../../index.html";
Entries[ 0 ] = "Home";

Files[ 1 ] = "../../ryabas.html";
Entries[ 1 ] = "Basic Approaches";

Files[ 2 ] = "../ryabasdivision.html";
Entries[ 2 ] = "Division";

Files[ 3 ] = "ryabasdivisionvolumes.html";
Entries[ 3 ] = "Volumes";

Files[ 4 ] = "ryabascylinders.html";
Entries[ 4 ] = "Cylinders";

Files[ 5 ] = "ryabascones.html";
Entries[ 5 ] = "Cones";

Files[ 6 ] = "ryabassphere.html";
Entries[ 6 ] = "Sphere";

Files[ 7 ] = "ryabasellipsoid.html";
Entries[ 7 ] = "Ellipsoid";

Files[ 8 ] = "ryabastori.html";
Entries[ 8 ] = "Tori";

Files[ 9 ] = "ryabasparaboloids.html";
Entries[ 9 ] = "Paraboloids";

Files[ 10 ] = "ryabas1shyperboloids.html";
Entries[ 10 ] = "One-sheeted hyperboloids";

Files[ 11 ] = "ryabas2shyperboloids.html";
Entries[ 11 ] = "Two-sheeted hyperboloids";

Files[ 12 ] = "ryabashoof.html";
Entries[ 12 ] = "Hoof";

Files[ 13 ] = "ryabassteinmetz.html";
Entries[ 13 ] = "Steinmetz";

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
