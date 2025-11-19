import React,{Component} from "react";

class Event extends Component {
    handleClick(){
        alert("i am clicked")
    }
    render(){
        return (
            <div onClick={this.handleClick}>
                click me
            </div>
        )
    }
}

export default Event;