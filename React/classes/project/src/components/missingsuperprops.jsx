import React,{Component} from "react";

class Output extends Component {
    constructor(props){
        super(props);
    
        this.state = {userName: this.props.name.toUpperCase()}
        // console.log("inside construtor with super(props)",this.props)
    }
    render(){
        console.log("inside render ",this.props);
        // return <h1> hello ,{this.props.name}</h1>
        return <h1> hello ,{this.state.nameState}</h1>
    }
}

export default Output;