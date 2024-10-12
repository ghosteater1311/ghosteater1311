function run(datas){
    var typeDates = [12 , "javascript", true, {type: "fruit", name: "Apple"} , 
                    {type: "Fiat", model: "500", color: "white"} , function(){} , undefined ];
    typeDates.forEach((elements)=>{console.log(typeof elements);})
}