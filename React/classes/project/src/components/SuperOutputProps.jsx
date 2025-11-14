import React,{Component} from "react";

class Output extends Component {
    constructor(props){
        super(props);
    
        console.log("inside construtor with super(props)",this.props)
    }
    render(){
        console.log("inside render ",this.props);
        return <h1> hello ,{this.props.name}</h1>
    }
}

export default Output;