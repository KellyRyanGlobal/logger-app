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
       echo '   <table border="1" width="100%
               	<col style="width:10%">
                  <col style="width:5%">
                  <col style="width:85%">' >> $html
       echo '<th colspan="2">Test Suite</th>' >> $html
       echo '<th colspan="2">Status</th>' >> $html
       echo '<th>Message</th>' >> $html
       while IFS=';' read -ra line ; do
        echo "<tr>" >> $html
        for i in "${line[@]}"; do
           echo "<td colspan="2">$i</td>" >> $html
          done
         echo "</tr>" >> $html
       done < $file
        echo '</table>' >> $html
        echo "   </body>" >> $html
        echo "</html>" >> $html
    done
