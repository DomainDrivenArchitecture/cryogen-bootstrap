{% if latest-posts|not-empty %}
    <h3>Recent Posts</h3>
    <ul>
    {% for post in latest-posts %}
        <li>
            {{post.date|date:"MMM dd"}} - <a href="{{post.uri}}">{{post.title}}</a>
        </li>   
    {% endfor %}
    </ul>
{% endif %}
