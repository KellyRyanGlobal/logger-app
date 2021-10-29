#! /bin/bash

    if [ $# -eq 0 ] ; then
       echo "USAGE: $(basename $0) file1 file2 file3 ..."
       exit 1
    fi

    for file in $* ; do
       html=$(echo $file | sed 's/\.txt$/\.html/i')

       echo "<html>" >> $html
       echo "<style type="text/css">
            table, th, td {
            border: 1px solid black;
            }
            </style>" >> $html
       echo "   <body>" >> $html
       echo '<table>' >> $htm
       echo '<th>HEADING1</th>' >> $html
       echo '<th>HEADING2</th>' >> $html
       echo '<th>HEADING3</th>' >> $html
       echo '<th>HEADING4</th>' >> $html
       while IFS=';' read -ra line ; do
        echo "<tr>" >> $html
        for i in "${line[@]}"; do
           echo "<td>$i</td>" >> $html
         # echo "<td>$i</td>" >> $html
          done
         echo "</tr>" >> $html
       done < $file
        echo '</table>'
        echo "   </body>" >> $html
        echo "</html>" >> $html
    done
