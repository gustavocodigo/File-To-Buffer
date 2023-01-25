# File-To-Buffer
<p>Simple data to buffer this file converts any file to a buffer of chars, good to embed Photos, Fonts memory in projects.,</p>


<h2>Build</h2>
gcc main.c -o tobuffer<br><br>
<p>
This line is optional to add to the system linux so you can call directly with terminal in any path as a command.</p>
<p>sudo mv ./tobuffer /bin/tobuffer</p>

<h2>Usage</h2>
tobuffer file output_file options


Options:
  -ps prefix[content]suffix  to add the prefix and suffix name example: tobuffer -ps 'const char * fonData = "[content]";'<br>
  you can use [size] and [content] where [size] is the optional size and [content] is the content.

