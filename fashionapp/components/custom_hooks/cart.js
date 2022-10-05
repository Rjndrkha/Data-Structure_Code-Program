import { useState } from 'react';
const defaultCart = {}

export default function useCart() {

  const [cart, updateCart] = useState(defaultCart);
    const [size, setSize] = useState(null)
    const[total , setTotal] = useState(0)
    
    const addToCart = (item) => {
        updateCart({
            ...cart,
            [item.id]: {
                ...item,
                quantity: 1,
                size: size	
            }
        })
    }
    function Cart(){
        return Object.values(cart)
    }
    const removeFromCart = (item) => {
        const newCart = { ...cart };
        delete newCart[item.id];
        updateCart(newCart);
    }

    const incrementQuantity = (item) => {
        updateCart({
            ...cart,
            [item.id]: {
                ...item,
                quantity: item.quantity + 1

            }

        })
    }

    const decrementQuantity = (item) => {
        if (item.quantity > 1) {
            updateCart({
                ...cart,
                [item.id]: {
                    ...item,
                    quantity: item.quantity - 1

                }

            })
        }

    }
    
    const clearCart = () => {
        updateCart(defaultCart)
    }

    const Subtotal = () => {
        for (const item in cart) {
            setTotal(cart[item].price * cart[item].quantity)
        }
        return total;
    }

    function getSize(size){
        setSize(size)
    }



  return {
    cart,
    addToCart,
    removeFromCart,
    incrementQuantity,
    decrementQuantity,
    clearCart,
    Subtotal,
    getSize,
    };
}

