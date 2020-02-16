<ul>
{% for post in latest-posts %}
    <li>
        {{post.date|date:"MMM dd"}} - <a href="{{post.uri}}">{{post.title}}</a>
    </li>   
{% endfor %}
</ul>
    