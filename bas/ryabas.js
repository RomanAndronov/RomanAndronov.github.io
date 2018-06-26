
var i;
var Files = new Array();
var Entries = new Array();

Files[ 0 ] = "../index.html";
Entries[ 0 ] = "Home";

Files[ 1 ] = "ryabas.html";
Entries[ 1 ] = "Basic Approaches";

Files[ 2 ] = "division/ryabasdivision.html";
Entries[ 2 ] = "Division";

Files[ 3 ] = "elimination/ryabaselimination.html";
Entries[ 3 ] = "Elimination";

Files[ 4 ] = "equation/ryabasequation.html";
Entries[ 4 ] = "Equation";

Files[ 5 ] = "equiv/ryabasequiv.html";
Entries[ 5 ] = "Equivalence";

Files[ 6 ] = "rearrangement/ryabasrearrangement.html";
Entries[ 6 ] = "Rearrangement";

Files[ 7 ] = "revorder/ryabasrevorder.html";
Entries[ 7 ] = "Reverse Order";

Files[ 8 ] = "expansion/ryabasexpansion.html";
Entries[ 8 ] = "Scope Expansion";

Files[ 9 ] = "reduction/ryabasreduction.html";
Entries[ 9 ] = "Scope Reduction";

Files[ 10 ] = "spacetime/ryabasspacetime.html";
Entries[ 10 ] = "Space Time";

Files[ 11 ] = "substitution/ryabassubstitution.html";
Entries[ 11 ] = "Substitution";

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
