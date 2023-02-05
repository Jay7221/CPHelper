QUESTION_TEMPLATE="Problem/"
function new()
{
    cp -r $QUESTION_TEMPLATE $1
}


${@:1}