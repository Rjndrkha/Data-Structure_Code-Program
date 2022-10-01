import CONFIG from '../../globals/config';

const getCategorie = (restaurant) => {
  const categories = restaurant.map((item) => item.name).join(', ');
  return categories;
};

const getCategories = (restaurant) => {
  let categories = '';
  restaurant.forEach((category) => {
    categories += `<p>${category.name}</p>`;
  });
  return categories;
};

const getMenuSkeleton = (count) => {
  let template = '';
  for (let i = 0; i < count; i += 1) {
    template += `
        <div class="list-menu__restaurant">
          <img class="list-menu__picture skeleton" src='./images/placeholder.jpg' alt='skeleton'>
          <div class="list-menu__name">
            <h3>Bebek Goreng</h3>
          </div>
        </div>
    `;
  }
  return template;
};

const getMenuFoods = (restaurant) => {
  let menus = '';
  restaurant.forEach((menu) => {
    menus += `
        <div class="list-menu__restaurant">
          <img class="list-menu__picture lazyload" data-src="${CONFIG.IMAGE_DEFAULT_FOOD_URL}" alt="Minuman ${menu.name}">
          <div class="list-menu__name">
            <h3>${menu.name}</h3>
          </div>
        </div>
    `;
  });
  return menus;
};

const getMenuDrinks = (restaurant) => {
  let menus = '';
  restaurant.forEach((menu) => {
    menus += `
      <div class="list-menu__restaurant">
        <img class="list-menu__picture lazyload" data-src="${CONFIG.IMAGE_DEFAULT_DRINK_URL}" alt="Minuman ${menu.name}">
        <div class="list-menu__name">
          <h3>${menu.name}</h3>
        </div>
      </div>
    `;
  });
  return menus;
};

const getReviews = (restaurant) => {
  let reviews = '';
  restaurant.forEach((review) => {
    reviews += `
      <div class="review-restaurant">
        <div style="display: flex; justify-content: space-between; align-items: center">
          <h3 class="review-restaurant__title">${review.name}</h3>
          <span class="review-restaurant__date">${review.date}</span>
        </div>
        <p class="review-restaurant__content">${review.review}</p>
      </div>
    `;
  });
  return reviews;
};

const getStarRating = (rating) => {
  let starsRating = '';
  // eslint-disable-next-line no-plusplus
  for (let i = 0; i < parseFloat(rating); i++) {
    if ((parseFloat(rating)) > i && i === (parseInt(rating, 10))) {
      starsRating += '<i class="fa fa-star-half-o" aria-hidden="true"></i> ';
    } else {
      starsRating += '<i class="fa fa-star" aria-hidden="true"></i> ';
    }
  }
  return starsRating;
};

const createRestaurantDetailTemplate = (restaurant) => `
<div class="hero__detail lazyload" style="
  background-image: linear-gradient(rgba(0, 0, 50, 0.5), rgba(0, 0, 100, 0.5)), url('${CONFIG.BASE_IMAGE_LARGE_URL + restaurant.restaurant.pictureId}');
  background-image: 
    -webkit-image-set(
      url('${CONFIG.BASE_IMAGE_SMALL_URL + restaurant.restaurant.pictureId}') 1x,
      url('${CONFIG.BASE_IMAGE_MEDIUM_URL + restaurant.restaurant.pictureId}') 2x,
    );
  background-image: 
    image-set(
      url('${CONFIG.BASE_IMAGE_SMALL_URL + restaurant.restaurant.pictureId}') 1x,
      url('${CONFIG.BASE_IMAGE_MEDIUM_URL + restaurant.restaurant.pictureId}') 2x,
    );">
        <div class="hero__inner">
            <h1 class="hero__title">${restaurant.restaurant.name}</h1>
            <p class="hero__tag">Kategori: ${getCategorie(restaurant.restaurant.categories)}</p>
        </div>
    </div> 
    <article class="content">
        <div class="headline__content-detail">
            <h2 class="headline__title-detail">${restaurant.restaurant.name}</h2>
            <div class="rating__detail">
                <span>${getStarRating(restaurant.restaurant.rating)}</span>
                <p style="padding-left: 5px">Total : (${restaurant.restaurant.rating})</p>
            </div>
            <h3 class="headline__sub-title"><i class="fa fa-map-marker" aria-hidden="true"></i> ${restaurant.restaurant.address}, ${restaurant.restaurant.city}</h3>
            
            <p class="headline__description">${restaurant.restaurant.description}</p>
            <h4 class="category__title">Kategori</h4>
            <div class="category__item">${getCategories(restaurant.restaurant.categories)}</div>
        </div>
    </article>
    <div class="latest">
      <h1 class="latest__label">List Menu</h1>
      <p class="latest__description">Terdapat makanan dan minuman yang berkualitas</p>
    </div>
    <div class="list-menu__container">
        ${getMenuFoods(restaurant.restaurant.menus.foods)}
        ${getMenuDrinks(restaurant.restaurant.menus.drinks)}
    </div>  
     
`;

const createRestaurantItemTemplate = (restaurant) => `
    <article class='post-item' key=${restaurant.id}>
      <div class='post-item__top'>
        <div class='post-item__tag'>
          <button class='post-item__tag__city'>Kota, ${restaurant.city}</button>
          <button class='post-item__tag__rating'>Rating: ${restaurant.rating}</button>
        </div>
          
        <img class='post-item__thumbnail lazyload'
          data-src='${restaurant.pictureId ? CONFIG.BASE_IMAGE_SMALL_URL + restaurant.pictureId : 'https://i.picsum.photos/id/666/800/450.jpg?grayscale&hmac=cijtLqs6SMxlZEcOinrh0ZHckTRMJXWjJc-ithauWk0'}'
          alt='Restaurant ${restaurant.name}'>
      </div>
      <div class='post-item__content'>
        <h1 class='post-item__title'><a href='${`/#/detail/${restaurant.id}`}' class='post-item__link' rel='noreferrer'>${restaurant.name || '-'}</a></h1>
        <p class='post-item__description'> ${restaurant.description || '-'} ...</p>
      </div>
    </article>
`;

const createLikeRestaurantButtonTemplate = () => `
  <button aria-label="like this restaurant" id="likeButton" class="like">
     <i class="fa fa-bookmark-o"" aria-hidden="true"></i>
  </button>
`;

const createUnlikeRestaurantButtonTemplate = () => `
  <button aria-label="unlike this restaurant" id="likeButton" class="like">
    <i class="fa fa-bookmark" aria-hidden="true"></i>
  </button>
`;

const createRestaurantDetailReviewTemplate = (restaurant) => `
  <div class="latest">
    <h1 class="latest__label">Review</h1>
    <p class="latest__description">Berikut review mengenai restoran ini dari pelanggan</p>
  </div>
  <div class="review__container">
      ${getReviews(restaurant.restaurant.customerReviews)}
  </div>
`;

const createSkeletonRestaurantTemplate = (count) => {
  let template = '';
  for (let i = 0; i < count; i += 1) {
    template += `
    <article class='post-item'>
      <div class='post-item__top'>
          <img class='post-item__thumbnail' src='./images/placeholder.jpg' alt='skeleton'>
      </div>
      <div class='post-item__content'>
          <h1 class='post-item__title skeleton'>Resto Kuno</h1>
          <p class='post-item__description skeleton'>
          Lorem ipsum dolor sit amet consectetur adipisicing elit. Veritatis possimus libero nemo sint eum saepe eligendi beatae explicabo ea quidem ipsam, accusamus voluptatibus suscipit ratione rerum voluptatum.</p>
      </div>
  </article>
    `;
  }
  return template;
};

const createSkeletonRestaurantDetailTemplate = (count) => ` 
  <div class="hero__detail" style="background-image: linear-gradient(rgba(0, 0, 50, 0.5), rgba(0, 0, 100, 0.5)), url('./images/placeholder.jpg')">
        <div class="hero__inner">
            <h1 class="hero__title skeleton">Resto Kuno</h1>
        </div>
    </div> 
    <article class="content">
        <div class="headline__content-detail">
            <h2 class="headline__title-detail skeleton">Resto Kuno</h2>
            <div class="rating__detail skeleton">
                <p style="padding-left: 5px">Total : Bintang 5</p>
            </div>
            <h3 class="headline__sub-title skeleton"><i class="fa fa-map-marker" aria-hidden="true"></i> Jl. Curung barat Kepanjen, Malang</h3>
            
            <p class="headline__description skeleton">Quisque rutrum. Aenean imperdiet. Etiam ultricies nisi vel augue. Curabitur ullamcorper ultricies nisi. Nam eget dui. Etiam rhoncus. Maecenas tempus, tellus eget condimentum rhoncus, sem quam semper libero, sit amet adipiscing sem neque sed ipsum. Nam quam nunc, blandit vel, luctus pulvinar, hendrerit id, lorem. Maecenas nec odio et ante.</p>
            <h4 class="category__title skeleton">Kategori</h4>
            <div class="category__item skeleton">Modern</div>
        </div>
    </article>
    <div class="latest">
      <h1 class="latest__label">List Menu</h1>
      <p>Terdapat makanan dan minuman yang berkualitas</p>
    </div>
    <div class="list-menu__container">
      ${getMenuSkeleton(count)}
    </div>    
`;

export {
  createRestaurantDetailTemplate,
  createRestaurantItemTemplate,
  createLikeRestaurantButtonTemplate,
  createUnlikeRestaurantButtonTemplate,
  createRestaurantDetailReviewTemplate,
  createSkeletonRestaurantTemplate,
  createSkeletonRestaurantDetailTemplate,
};
