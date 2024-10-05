function display_result(sum) {
	console.log('sum is ' + sum);
}
function add_two_numbers(callback, a, b) {
	var sum = a + b;
    callback(sum);
}

function run() {
	var a = 5;
	var b = 7;
	add_two_numbers(display_result, a, b);
}