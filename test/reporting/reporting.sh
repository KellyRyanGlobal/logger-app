#!/usr/bin/env bash

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
       echo '<th>Test Suite</th>' >> $html
       echo '<th>Status</th>' >> $html
       echo '<th>Message</th>' >> $html
       while IFS=';' read -ra line ; do
        echo "<tr>" >> $html
        for i in "${line[@]}"; do
           echo "<td>$i</td>" >> $html
          done
         echo "</tr>" >> $html
       done < $file
        echo '</table>'
        echo "   </body>" >> $html
        echo "</html>" >> $html
    done
