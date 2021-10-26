import RestaurantSource from '../../data/restaurant-source';
import { createRestaurantItemTemplate, createSkeletonRestaurantTemplate } from '../templates/template-creator';

const Home = {
  async render() {
    return `
    <div class="hero">
        <div class="hero__inner">
            <h1 class="hero__title">Temukan makanan kuno dengan rasa yang mengikat</h1>
            <p class="hero__tagline">Dimasak dengan sistem penggorengan kuno, yang berada di tanah jawa. Sehingga memiliki nuansa seperti pada zaman dahulu</p>
        </div>
    </div> 
    <section class="content">
        <article class="headline">
            <figure class="headline__figure">
                <source type="image/webp" media="(max-width: 600px)" srcset="./images/heros/hero-image_2.webp">
                <source type="image/jpeg" media="(max-width: 600px)" srcset="./images/heros/hero-image_2-small.jpg">
                <img src="../images/heros/hero-image_2.webp" width="480px" height="320px" alt="About Resto Kuno">
                <figcaption>Resto Kuno April 2021</figcaption>
            </figure>
            <div class="headline__content">
                <h1 class="headline__title">#ceritarestokuno : Story of Resto Kuno</h1>
                <p class="headline__description">Lorem ipsum dolor sit amet, consectetur adipisicing elit. Delectus eum
                    facere nostrum officiis qui quidem ratione similique, soluta veniam voluptatum. Accusantium ad amet
                    asperiores, aut commodi corporis dicta distinctio ducimus expedita itaque laudantium magnam maiores,
                    nobis obcaecati officiis provident quasi qui quos repellat rerum saepe sint soluta veniam vero
                    vitae, voluptas voluptate voluptatem. Esse nobis non nulla optio vero. Laudantium!</p>
            </div>
        </article>
        <div class="latest">
            <h1 class="latest__label">Jelajahi lebih lanjut</h1>
            <p class="latest__description">Resto Kuno sudah tersebar di berbagai daerah</p>
            <div id="posts" class="posts">
              ${createSkeletonRestaurantTemplate(20)}
            </div>
        </div>
    </section>
    `;
  },

  async afterRender() {
    const listRestaurants = await RestaurantSource.exploreRestaurants();
    const listRestaurantsContainer = document.querySelector('#posts');
    listRestaurantsContainer.innerHTML = '';
    listRestaurants.forEach((restaurant) => {
      listRestaurantsContainer.innerHTML += createRestaurantItemTemplate(restaurant);
    });
  },
};

export default Home;
