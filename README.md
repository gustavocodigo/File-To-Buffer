# File-To-Buffer
<h1>Simple data to buffer this file converts any file to a buffer of chars, good to embed Photos, Fonts memory in projects.,</h1>


<h2>Build</h2>
gcc main.c -o tobuffer
<h2>Usage</h2>
tobuffer <file> <output_file> <options>
Options:
  -ps prefix[content]suffix  to add the prefix and suffix name example: tobuffer -ps 'const char * fonData = "[content]";'
  you can use [size] and [content] where [size] is the optional size and [content] is the content.
