import { StyleSheet, Text, View, Image, ScrollView, TouchableOpacity } from 'react-native'
import React, { useState } from 'react'
import Categories from './Categories'
import Section from './Section'
import Crousal from './Crousal'
import Nav from './Nav'


export default function Home() {
    const [categories, setCategories] = useState([
        {
            id: 134,
            name: 'All',
            image: require('../assets/images/all.png'),
        },
        {
            id: 2324,
            name: 'Male',
            image: require('../assets/images/man.png'),
        },
        {
            id: 3324,
            name: 'Female',
            image: require('../assets/images/women.png'),
        },
        {
            id: 4342,
            name: 'Kids',
            image: require('../assets/images/kids.png'),
        },
        {
            id: 5342,
            name: 'Shoes',
            image: require('../assets/images/shoes.png'),
        },


    ])

    const [topRated, setTopRated] = useState([
       {
            id: 1,
            name: `The Drop Women's Britt Tiered Maxi Tent Dress`,
            price: 59.90,
            image: require("../assets/images/toprated/1.jpg")
       },
       {
            id: 2,
            name: `Dress the Population Women's Bodycon`,
            price: 148.00,
            image: require("../assets/images/toprated/2.jpg")
       },
       {
            id: 3,
            name: `Women's Half-Sleeve Waisted Midi A-Line Dress`,
            price: 30.60,
            image: require("../assets/images/toprated/3.jpg")
       },
       {
            id: 4,
            name: `The Drop Women's @caralynmirand Ruffle-Neck Tiered Mini Dress`,
            price: 49.00,
            image: require("../assets/images/toprated/4.jpg")
       },
       {
            id: 5,
            name: `Calvin Klein womens Solid Sheath With Chiffon Bell Sleeves Dress`,
            price: 89.95,
            image: require("../assets/images/toprated/5.jpg")
       },
       {
            id: 6,
            name: `The Drop Women's Gabriela High Neck Cut-In A-Line Side Slit Maxi Sweater Dress`,
            price: 49.90,
            image: require("../assets/images/toprated/6.jpg")
       },
       {
            id: 7,
            name: `Norma Kamali Women's Halter Turtle Side Slit Gown`,
            price: 145.00,
            image: require("../assets/images/toprated/7.jpg")
       },
       {
            id: 8,
            name: `The Drop Women's Ana Silky V-Neck Midi Slip Dress`,
            price: 49.90,
            image: require("../assets/images/toprated/8.jpg")
       },
       {
            id: 9,
            name: `Dress the Population Women's Audrey Spaghetti Strap Midi A-line 3D Floral Dress`,
            price: 289.00,
            image: require("../assets/images/toprated/9.jpg")
       },
       {
            id: 10,
            name: `The Drop Women's Lu Wide Strap Soft Smocked Midi Dress`,
            price: 54.90,
            image: require("../assets/images/toprated/10.jpg")
       },
       {
            id: 11,
            name: `Women's Short-Sleeve Maxi Dress`,
            price: 28.20,
            image: require("../assets/images/toprated/11.jpg")
       },
       {
            id: 12,
            name: `Kasper Women's Sleeveless Sheath Dress`,
            price: 79.00,
            image: require("../assets/images/toprated/12.jpg")
       },
       {
            id: 13,
            name: `Gildan Men's Crew T-Shirts, Multipack, Style G1100`,
            price: 18.99,
            image: require("../assets/images/toprated/13.jpg")
       },
       {
            id: 14,
            name: `Stranger Things mens Stranger Things Hellfire Club Young Men's 3/4 Sleeve Raglan Tee`,
            price: 27.99,
            image: require("../assets/images/toprated/14.jpg")
       },
       {
            id: 15,
            name: `Gildan Men's V-Neck T-Shirts, Multipack`,
            price: 14.99,
            image: require("../assets/images/toprated/15.jpg")
       },
       {
            id: 16,
            name: `Carhartt Men's Loose Fit Heavyweight Short-Sleeve Pocket T-Shirt`,
            price: 24.99,
            image: require("../assets/images/toprated/16.jpg")
       },
       {
            id: 17,
            name: `Men's Regular-Fit Long-Sleeve Plaid Poplin Shirt`,
            price: 18.50,
            image: require("../assets/images/toprated/17.jpg")
       },
       {
            id: 18,
            name: `Jerzees Men's SpotShield Stain Resistant Polo Shirts (Short & Long Sleeve)`,
            price: 9.95,
            image: require("../assets/images/toprated/18.jpg")
       },
       {
            id: 19,
            name: `Hanes Men's Short Sleeve X-Temp W/ FreshIQ Polo`,
            price: 13.00,
            image: require("../assets/images/toprated/19.jpg")
       },
       {
            id: 20,
            name: `Paul Jones Men's Long Sleeves Button Down Dress Shirts`,
            price: 25.49,
            image: require("../assets/images/toprated/20.jpg")
       },
       {
            id: 21,
            name: `Carhartt Men's Loose Fit Heavyweight Short-Sleeve Logo Graphic T-Shirt`,
            price: 19.99,
            image: require("../assets/images/toprated/21.jpg")
       },
       {
            id: 22,
            name: `Hanes Men's Beefy Long Sleeve Three-Button Henley`,
            price: 9.50,
            image: require("../assets/images/toprated/22.jpg")
       },
       {
            id: 23,
            name: `Men's Slim-Fit Cotton Pique Polo Shirt`,
            price: 16.30,
            image: require("../assets/images/toprated/23.jpg")
       },
       {
            id: 24,
            name: `Van Heusen Men's Short Sleeve Dress Shirt Regular Fit Poplin Solid`,
            price: 22.99,
            image: require("../assets/images/toprated/24.jpg")
       },


    ])

    return (
        <View style={styles.homeScreen}>
            <ScrollView
                showsVerticalScrollIndicator={false}
                contentContainerStyle={{
                    flexGrow: 1,
                }}>
                <Nav/>
                <View style={styles.homeScreenBody}>
                    <Text style={styles.heading}>
                        Find your style.
                    </Text>
                    <Categories categories={categories} />
                </View>

                <Crousal/>
                <Section section={'Top Rated'} data={topRated} />

            </ScrollView>
        </View>
    )
}

const styles = StyleSheet.create({
    homeScreen: {
        padding: 20,
        // marginBottom: 40,'
        paddingBottom:10,
    },
    
    homeScreenBody: {
        marginTop: 10,
        width: '100%',
    },
    heading: {
        color: '#000',
        fontSize: 35,
        fontWeight: 'bold',
        marginTop: 10,
    },
    cPic: {
        width: 200,
        height: 300,
        marginRight: 25,
    },
   
})