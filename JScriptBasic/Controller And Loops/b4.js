function run(the_number) {
	var day_of_week_name = '';
    switch (the_number) {
        case "0" : 
            day_of_week_name = "Sunday"; 
            break;
        case "1" :
            day_of_week_name = "Monday"; 
            break;
        case "2" :
            day_of_week_name = "Tuesday"; 
            break;
        case "3" :
            day_of_week_name = "Wednesday"; 
            break;   
        case "4" :
            day_of_week_name = "Thursday"; 
            break;
        case "5" :
            day_of_week_name = "Friday"; 
            break; 
        case "6" :
            day_of_week_name = "Saturday"; 
            break;
        default :
            break;  
    }
    console.log(day_of_week_name);
}
