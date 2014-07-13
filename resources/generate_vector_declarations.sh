cat interrupt_names.txt | sed 's/ *(.*)//' | sed 's@[/ -]@_@g' | sed 's/μ/u/g' | tr '[:upper:]' '[:lower:]' | sed 's/^/vector_/' > function_style_interrupt_names

cat function_style_interrupt_names | awk 'END{print "vector_reserved"} !/vector_reserved/{print $0}' | while read line; do printf "INTERRUPT_DEF %s;\n" "$line()"; done > interrupt_declarations.cpp

cat function_style_interrupt_names | while read line; do echo "   $line,"; done > isr_vector_members.cpp
