<?php

/*
lophty directory indexer
copyright 2001 brian donovan, indexer-script@lophty.com


Patch Contributors 

Sept 09, 2001
Tim Waugh (tim@cyberelk.net, http://www.cyberelk.net/tim/)
Added support for multi-dot file names (ex. stuff.under.mytoenail.foo as 
opposed to single-dot file names like stuff.foo)


This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#---------------------------------------------------
/*
$thisFileName  : the name of this file

$thisDirectory : the path to the directory in which this page sits.  For
	Apache-served sites, you can use the predefined $REQUEST_URI variable.
	Note that you can also specify a string, like a full url, but this will not affect 
	the directory that's actually indexed. :D

$thisPageFilesDir : the name of a directory in which we'll put the css file and gifs that we need to beautify this page
	Note that you don't have to put those files into a directory separate from this file.  I just do it to make global changes
	for all of these indexing pages possible - by putting the css file and gifs into a folder and then giving $thisPageFilesDir 
	the value of the path to that folder, you can update the bullets or the general appearance of the page by changing a few files
	in one location.  If you want to put these files into the same directory as this page, that's fine - just give $thisPageFilesDir
	a value of "" 

$bulletImgsArr : holds the filenames of the images used as bullets

Finally, remember to change the permissions on subdirectories that will be listed by this script if you would like visiors to be 
able to drill down into them
*/
#---------------------------------------------------

$thisFileName = "index.php";
$thisDirectoryPath = $REQUEST_URI;

$thisServerName = $SERVER_NAME;

$thisPageFilesDir = "indexerfiles/";

$thisPageCssFile= $thisPageFilesDir."dirindexer.css";

$fileImgProps = array('filepath' => $thisPageFilesDir."file.gif", 'height' => '13', 'width' => '13');
$dirImageProps = array('filepath' => $thisPageFilesDir."dir.gif", 'height' => '13', 'width' => '13');
$bulletImgsArr = array('fileImg' => $fileImgProps, 'dirImg' => $dirImageProps);

#---------------------------------------------------
/*
Add the name of this file and the namess of the files and dirs used with it to arrays.  When the files and directories
are read in, files and dirs in these 2 arrays will not by listed or counted when this page is viewed.  If there are any other files 
other than those actually used by this page that you'd rather not have so readily available to others through this page, you can
add them into these arrays
*/
#---------------------------------------------------


$dontListFiles = array($thisFileName, $bulletImgsArr['dirImg']['filepath'], $bulletImgsArr['fileImg']['filepath'], $thisPageCssFile);
$dontListDirs = array($thisPageFilesDir, "cgi-bin", "indexerfiles");

function getThisDirName($url)
{
	#---------------------------------------------------
	/*
		getThisDirName : Accepts the path to the directory either in the form of $REQUEST_URI
			or a string value and pulls out the directory name
	*/
	#---------------------------------------------------
	$afterCutOne = substr($url, 0, strrpos($url, "/"));
	$afterCutTwo = substr($afterCutOne, strrpos($afterCutOne, "/") - strlen($afterCutOne) + 1);
	return $afterCutTwo;
}

#---------------------------------------------------
/*
	isort and isortMultiD are 2 sorting functions used to add pseudo
		alphabetical order to the list of directory names and file names
*/
#---------------------------------------------------

function isort($a,$b)
{
	#---------------------------------------------------
	/*
		isort : 

			ord (http://www.php.net/manual/en/function.ord.php) returns the ASCII value of the first character in a string (the ASCII value of a capital letter is different from that of a lower case letter)

			strtolower  (http://www.php.net/manual/en/function.strtolower.php) converts all uppercase chrs in a string to lowercase

			This function compares the lower-cased first letter in one string to that in another.  We'll use it to compare directory names
	*/
	#---------------------------------------------------
	if(ord(strtolower($a)) == ord(strtolower($b))) return 0;
	return (ord(strtolower($a))< ord(strtolower($b))) ? -1: 1;
}

function isortMultiD($a,$b)
{
	#---------------------------------------------------
	/*
		isortMultiD : This function basically is the same as issort, except that it runs the comparison between the 2nd row in each array, then the first.
			We'll be using it to sort the filenames, where the j in $filesArr[i][j] is the extension (bmp, gif, jpg, etc) and the i is the name itself.
	*/
	#---------------------------------------------------
    if(ord(strtolower($a[count($a) - 1])) == ord(strtolower($b[count ($b) - 1])))
	{
		if(ord(strtolower($a[0])) == ord(strtolower($b[0]))) return 0;
		return (ord(strtolower($a[0]))< ord(strtolower($b[0]))) ? -1: 1;
	}
	return (ord(strtolower($a[count ($a) - 1])) < ord(strtolower($b[count ($b)]))) ? -1: 1;
}

function indexdirThisDir()
{
	#---------------------------------------------------
	/*
		indexdirThisDir : This function scours through the current directory (regardless of which directory u specify via the getThisDirName call)
			and makes a list of directories and does the same for files,  first by their extensions
			and then by their names.  Remember that since it's only alphabetical on the first char php and phtml or php3 and php files will be jumbled together, 
			as will html and htm (the same logic holds for file names).
	*/
	#---------------------------------------------------
	global $bulletImgsArr;
	global $dontListFiles;
	global $dontListDirs;

	$numHiddenDirs = 0;
	$numHiddenFiles = 0;

	$dirsArr = array();
	$filesArr = array();

	$this_dir_handle=opendir('.'); # get a handle on the current directory
	while (false!==($fileORdir = readdir($this_dir_handle)))
	{
		if ($fileORdir != "." && $fileORdir != "..")
		{
			if(is_dir($fileORdir)== false)
			{
				$thisFileNoShow = 0;
				for ($i = 0; $i < count($dontListFiles); $i++)
				{
					if($fileORdir == $dontListFiles[$i])
					{
						$thisFileNoShow = 1;
						$numHiddenFiles++;
						break;
					}
				}
				if($thisFileNoShow == 0)
				{
					$fileNameAndextensionArr = explode(".", $fileORdir);
					array_push ($filesArr, $fileNameAndextensionArr);
				}
			}
			else
			{
				$thisDirNoShow = 0;
				for ($i = 0; $i < count($dontListDirs); $i++)
				{
					if($fileORdir == $dontListDirs[$i])
					{
						$thisDirNoShow = 1;
						$numHiddenDirs++;
						break;
					}
				}
				if($thisDirNoShow == 0)
				{
				array_push ($dirsArr, $fileORdir);
				}
			}
		}
	}
	closedir($this_dir_handle);
	
	$listingHTML .= "<div id=\"thisdircontains\">contains ".count($dirsArr)." subdirectories and ".count($filesArr)." files </div>\n";

	usort($dirsArr, 'isort');
	usort($filesArr, 'isortMultiD');

	$listingHTML .="\n<div id=\"dirslist\">\n";
	for ($i = 0; $i < count($dirsArr); $i++)
	{
		$listingHTML .= "<a href=\"".$dirsArr[$i]."/\" class =\"dirs\"><img src=\"".$bulletImgsArr['dirImg']['filepath']."\" height=\"".$bulletImgsArr['dirImg']['height']."\" width=\"".$bulletImgsArr['dirImg']['width']."\" alt=\"file\" />".$dirsArr[$i]."</a> <br /> \n";
	}
	$listingHTML .="</div>\n\n";

	$listingHTML .="<div id=\"fileslist\">\n<table>\n<tr><td>file</td><td>size (kb)</td><td>last modified</td></tr>\n";
	for ($i = 0; $i < count($filesArr); $i++)
	{
		$filesArr[$i] = join (".", $filesArr[$i]);
		$fileStats = stat($filesArr[$i]);
		$fileSizeInKb = round(($fileStats[7]/1024),2);
		$fileLastMod = date("H : i  M dS Y", $fileStats[9]);
		$listingHTML .= "<tr><td><a href=\"".$filesArr[$i]."\" class =\"files\"><img src=\"".$bulletImgsArr['fileImg']['filepath']."\" height=\"".$bulletImgsArr['fileImg']['height']."\" width=\"".$bulletImgsArr['fileImg']['width']."\" alt=\"file\" />".$filesArr[$i]."</a></td><td class=\"filedetails\">".$fileSizeInKb."</td><td class=\"filedetails\">".$fileLastMod."</td></tr> \n";
	}
	$listingHTML .='</table></div>';

	return $listingHTML;
}

$thisDirName = getThisDirName($thisDirectoryPath);
$listingHTMLstring = indexdirThisDir();

header( "Content-type: text/html" );

print ("
<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">
<html xmlns=\"http://www.w3.org/1999/xhtml\" xml:lang=\"en\" lang=\"en\" >
<head>
<title>index of $thisDirName</title>
<link rel=\"stylesheet\" type=\"text/css\" href=\"$thisPageCssFile\" />
</head>

<body>
<h1>$thisDirName</h1>
$listingHTMLstring



</body>
</html>");
?>

