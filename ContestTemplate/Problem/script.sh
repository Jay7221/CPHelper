function compile()
{
	g++ -std=c++17 -o $1 $1.cpp
}
function execute()
{
	echo ${@:2}
	./$1 ${@:2}
}

function gt()
{
	# Generates testcases
	# At most one optional arg, number of testcases to generate
	n=10
	if [ $1 ]
	then
		n=$1
	fi
	compile generator
	for (( i = 1 ; i <= n ; ++i ))
	do
		echo "Generating TestCase $i --"
		./generator > testcases/testcase$i.txt
		read -t 3 -p "Since calling time(0) in same second gives same value and thus same testcase, we will wait for some time."
		echo
		echo "Done Generating TestCase $i !!"
	done
}
function gs()
{

	# Generates solution testcases
	# At most one optional arg, number of testcases to generate solution for
	n=10
	if [ $1 ]
	then
		n=$1
	fi
	compile solution
	for (( i = 1 ; i <= n ; ++i ))
	do
		echo "Generating Solution For TestCase $i --"
		./solution < testcases/testcase$i.txt > expected_outputs/expected_output$i.txt
		echo "Done Generating Solution For TestCase $i !!"
	done
}

function run()
{
        n=10
        if [ $1 ]
        then
                n=$1
        fi
        compile testSol
        for (( i = 1 ; i <= n ; ++i ))
        do
				echo "Running TestCase $i --"
                ./testSol < testcases/testcase$i.txt > outputs/output$i.txt
				echo "Done Running TestCase $i !!" 
        done
}
function check()
{
	# This function runs the checker file, to check whether the output produced by the test solution is correct
	n=10
	if [ $1 ] 
	then
		n=$1
	fi
	compile checker
	for (( i = 1 ; i <= n ; ++i ))
	do
		./checker testcases/testcase$i.txt outputs/output$i.txt expected_outputs/output$i.txt
	done
}

function cleanUp()
{
	arr=("solution" "checker" "testSol" "generator" "main")
	for item in ${arr[@]}
	do
		rm -f $item
	done
	
}

# This will execute all words except the first (which will be ./script)
# echo ${@:1}
${@:1}
