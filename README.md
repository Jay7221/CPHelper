# Project_Manager
A project manager applicaton that eliminates the time required to write repetative code by using premade code templates.

##  commands
    cpmanager new contest [CONTEST_NAME]

Creates a new folder by the name of the [CONTEST_NAME], and adds the following files to it - 
<ul>
  <li> <b>inputf.in</b></li>
  <li> <b>outputf.out</b></li>
  <li> <b>settings.json</b> <br>
    This file contains - 
    <ul type = "circle">
      <li> DEFAULT_FILE - The file to be executed by default </li>
      <li> CONTEST_NAME</li>
      <li> ORGANIZATION_NAME</li>
    </ul>
  </li>
</ul>


    cpmanager new file [FILE_NAME]

Creates a new file and sets it to default for execution.

    cpmanager execute [FILE_NAME]

If no filename is given executes the default file.
# CPHelper
