# File-To-Buffer
<p>Simple data to buffer this file converts any file to a buffer of chars, good to embed Photos, Fonts memory in projects.,</p>


<h2>Build</h2>
gcc main.c -o tobuffer
<h2>Usage</h2>
tobuffer file output_file options


Options:
  -ps prefix[content]suffix  to add the prefix and suffix name example: tobuffer -ps 'const char * fonData = "[content]";'<br>
  you can use [size] and [content] where [size] is the optional size and [content] is the content.



<h3>example<h3>
<h4>example 1</h4>
![image](https://user-images.githubusercontent.com/108258194/214454673-5276b86d-299a-4315-b4cf-b99827dfdd68.png)
<p>result where the content of FILE.txt is "hELLO"<p>
![image](https://user-images.githubusercontent.com/108258194/214454929-fbe7f955-392c-437b-a65a-c6197ddd8527.png)
<h2>example 2</h4>
![image](https://user-images.githubusercontent.com/108258194/214455582-4c4a01eb-416f-40a0-bb27-7b70c8682a67.png)
<P>result</p>
![image](https://user-images.githubusercontent.com/108258194/214455650-49438b2d-d831-4990-8bbe-611398af7d75.png)
