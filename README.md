# Tree-Command-of-Linux-Using-C
Tree Command- This is tree command of linux using C language. In this I have used string library , file opening and directory opening concept.
This is the implementation of tree command in linux using C
Usage:
	./project pathname/absolute_paths -options

Special cases:
	You can also use the options for the command with combined usage.

Options:
	1)no option - 	in this mode the command displays the directories and the files
			in the manner such that the directories are shown at an indented
			distance of |----- and the files in that directory are shown 
			below the directory.		
		
	2) -d -		This option displays the folders inside the path given
				
	3) -f -		Print the full path prefix for each file.          
  	
	4) -l -         Follow symbolic links like directories.           		
		
	5) -i -         Don't print indentation lines.	
