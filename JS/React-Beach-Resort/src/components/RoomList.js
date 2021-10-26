import React from 'react'
import Room from './Room'

export default function RoomList({rooms}) {
    if(rooms.length === 0){
        return (
            <div className="empty-search">
                <h3>just testing</h3>
            </div>
        );
    }
    return(
        <section className="roomslist">
            <div className="roomslist-center">
                {rooms.map(item => {
                    return <Room key={item.id} room={item}/>;
                })}
            </div> 
        </section>
    )
}
