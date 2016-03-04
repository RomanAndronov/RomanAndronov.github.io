var	i;
var	Files = new Array();
var	Entries = new Array();

Files[ 0 ] = "../index.html";
Entries[ 0 ] = "Home";

Files[ 1 ] = "ryapdpic.html";
Entries[ 1 ] = "Cover";

Files[ 2 ] = "ryapdpicpreface.html";
Entries[ 2 ] = "Preface";

Files[ 3 ] = "ryapdpicintro.html";
Entries[ 3 ] = "Introduction";

Files[ 4 ] = "ryapdpicencapsulation.html";
Entries[ 4 ] = "Encapsulation patterns";

Files[ 5 ] = "ryapdpichandle.html";
Entries[ 5 ] = "&nbsp;&nbsp;&nbsp;Handle";

Files[ 6 ] = "ryapdpicadt.html";
Entries[ 6 ] = "&nbsp;&nbsp;&nbsp;ADT";

Files[ 7 ] = "ryapdpicchainedlinking.html";
Entries[ 7 ] = "Chained Linking";

Files[ 8 ] = "ryapdpiccomposition.html";
Entries[ 8 ] = "Composition";

Files[ 9 ] = "ryapdpicintegralparts.html";
Entries[ 9 ] = "&nbsp;&nbsp;&nbsp;Integral Parts";

Files[ 10 ] = "ryapdpicnonintegralparts.html";
Entries[ 10 ] = "&nbsp;&nbsp;&nbsp;Non-integral Parts";

Files[ 11 ] = "ryapdpiccreate.html";
Entries[ 11 ] = "Creational patterns";

Files[ 12 ] = "ryapdpicfactory.html";
Entries[ 12 ] = "&nbsp;&nbsp;&nbsp;Factory";

Files[ 13 ] = "ryapdpicabstractfactory.html";
Entries[ 13 ] = "&nbsp;&nbsp;&nbsp;Abstract Factory";

Files[ 14 ] = "ryapdpicbuilder.html";
Entries[ 14 ] = "&nbsp;&nbsp;&nbsp;Builder";

Files[ 15 ] = "ryapdpicprototype.html";
Entries[ 15 ] = "&nbsp;&nbsp;&nbsp;Prototype";

Files[ 16 ] = "ryapdpicsingleton.html";
Entries[ 16 ] = "&nbsp;&nbsp;&nbsp;Singleton";

Files[ 17 ] = "ryapdpicstruct.html";
Entries[ 17 ] = "Structural patterns";

Files[ 18 ] = "ryapdpicadapter.html";
Entries[ 18 ] = "&nbsp;&nbsp;&nbsp;Adapter";

Files[ 19 ] = "ryapdpicdecorator.html";
Entries[ 19 ] = "&nbsp;&nbsp;&nbsp;Decorator";

Files[ 20 ] = "ryapdpicbridge.html";
Entries[ 20 ] = "&nbsp;&nbsp;&nbsp;Bridge";

Files[ 21 ] = "ryapdpicbehave.html";
Entries[ 21 ] = "Behavioral patterns";

Files[ 22 ] = "ryapdpicextender.html";
Entries[ 22 ] = "&nbsp;&nbsp;&nbsp;Extender";


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
