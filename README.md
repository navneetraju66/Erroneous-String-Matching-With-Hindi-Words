GO TO hindi.c FILE LOCATED INSIDE src FOLDER
LOOK FOR COMMENTS TO SEE WHERE TO GIVE 

installations:
`sudo apt-get install libglib2.0-dev`

command to compile hindi.c:
`gcc -Wall -o hindi hindi.c $(pkg-config --cflags --libs glib-2.0)`
